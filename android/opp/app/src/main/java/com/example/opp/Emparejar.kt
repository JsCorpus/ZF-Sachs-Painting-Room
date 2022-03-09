package com.example.opp

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import ingenieria.jhr.bluetoothjhr.BluetoothJhr
import kotlinx.android.synthetic.main.activity_emparejar.*

class Emparejar : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_emparejar)
      emparejamiento()
    }

  fun emparejamiento(){
    //pasar a la siguiente activity al presionar el dispositivo bluethoth
    val blue = BluetoothJhr(this,pantalla, Paintinroom::class.java)
    //para listView normal solo accedemos a onBluetooth
    blue.onBluetooth()
    //mostrar los dispositivos bluethooth
    pantalla.setOnItemClickListener { adapterView, view, i, l ->
      blue.bluetoothSeleccion(i)
      finish()
    }
  }
}
