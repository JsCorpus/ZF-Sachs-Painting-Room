package com.example.opp

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.os.CountDownTimer
import android.view.View

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        //se le agrega los milisegundos de carga y lo haces llamar para mostrarlo

        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        pantallaCarga()
    }
    fun pantallaCarga(){
        object: CountDownTimer(1500,1000){
            override fun onTick(p0: Long) {

            }

            override fun onFinish() {
                val intent= Intent(this@MainActivity,Bienvenido::class.java).apply{}
                startActivity(intent)
              //destruye la activity
              finish()
            }

        }.start()
    }

}
