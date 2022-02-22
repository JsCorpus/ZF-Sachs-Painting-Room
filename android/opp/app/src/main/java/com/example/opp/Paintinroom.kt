package com.example.opp

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import ingenieria.jhr.bluetoothjhr.BluetoothJhr
import kotlinx.android.synthetic.main.activity_paintinroom.*
import kotlin.concurrent.thread

class Paintinroom : AppCompatActivity() {
    lateinit var blue : BluetoothJhr
    var inithilo = false
    var hilo = false
    var mensaje= ""

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_paintinroom)
        //
        blue = BluetoothJhr(this, MainActivity::class.java)

        //seccion del temometro


        thread(start = true){
            while (!inithilo){
                Thread.sleep(500)
            }

            while (hilo){
                blue.mTx("t")
                Thread.sleep(1000)
                mensaje=blue.mRx()
                if (mensaje!=""){
                   runOnUiThread({pantallaTemperatura.text=mensaje }
                   )
                }else{
                    break
                }
                blue.mensajeReset()

            }
            Thread.sleep(1000)
        }



    }
    override fun onResume() {
        super.onResume()
        inithilo =  blue.conectaBluetooth()

    }

    override fun onPause() {
        super.onPause()
        hilo = true
        inithilo=true
        blue.exitConexion()
        finish()
    }

    override fun onDestroy() {
        super.onDestroy()
        inithilo=true
        hilo=false
    }

    fun Pruebasonora(vista: View){
        val intent= Intent(this,PruebaSonora::class.java)
        startActivity(intent)
    }
    fun pruebavisual(vista:View){
        val intent= Intent(this,PruebaVisual::class.java)
        startActivity(intent)
    }
}