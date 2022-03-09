package com.example.opp

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import android.widget.Toast
import ingenieria.jhr.bluetoothjhr.BluetoothJhr
import kotlinx.android.synthetic.main.activity_paintinroom.*
import kotlin.concurrent.thread

class Paintinroom : AppCompatActivity() {
    lateinit var blue : BluetoothJhr
    var inithilo = false
    var hilo = false
    var mensaje= ""
    var contador = "0"

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_paintinroom)
      datosBluetooth()
    }

  fun datosBluetooth(){
    //
    blue=BluetoothJhr(this,Emparejar::class.java)
    //seccion del termometro
    thread(start = true){
      while (!inithilo){
        Thread.sleep(500)
      }

      while (!hilo){
        //Encender led
        blue.mTx("t")

        Thread.sleep(1000)
        mensaje=blue.mRx()
        contador = mensaje.length.toString();
        blue.mTx(contador)
        if (contador == "9" ){
          runOnUiThread({pantallaTemperatura.text=mensaje})
        }else if(contador == "8" ){
          runOnUiThread({pantallaHumedad.text=mensaje})
        }else {

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
        hilo=true
    }

    fun Pruebasonora(vista: View){
      blue.mTx("1")
      Thread.sleep(1000)
      Toast.makeText(this, "Realizando prueba sonora", Toast.LENGTH_SHORT).show()
    }
    fun pruebavisual(vista:View){
      blue.mTx("3")
      Thread.sleep(1000)
      Toast.makeText(this, "Realizando prueba visual", Toast.LENGTH_SHORT).show()
    }
}
