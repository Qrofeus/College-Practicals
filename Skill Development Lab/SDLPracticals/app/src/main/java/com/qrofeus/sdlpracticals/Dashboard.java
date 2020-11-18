package com.qrofeus.sdlpracticals;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;

public class Dashboard extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_dashboard);
    }

    public void audioPlayer(View view){
        startActivity(new Intent(Dashboard.this, AudioPlayer.class));
    }

    public void storeData(View view){
        startActivity(new Intent(Dashboard.this, FileStorage.class));
    }

    public void gpsLocator(View view){
        startActivity(new Intent(Dashboard.this, LocationSearch.class));
    }
}