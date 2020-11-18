package com.qrofeus.sdlpracticals;

import android.annotation.SuppressLint;
import android.media.MediaPlayer;
import android.net.wifi.aware.DiscoverySession;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.view.View;
import android.widget.Button;
import android.widget.SeekBar;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

public class AudioPlayer extends AppCompatActivity {

    private MediaPlayer mp = null;
    private int playTime = 0;

    private Button playPause;
    private SeekBar playbackBar;
    private TextView elapsedLabel;
    private TextView remainLabel;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_audio_player);

        playPause = findViewById(R.id.playPause);
        elapsedLabel = findViewById(R.id.elapsedLabel);
        remainLabel = findViewById(R.id.remainingLabel);
        playbackBar = findViewById(R.id.playbackBar);
        SeekBar volumeBar = findViewById(R.id.volumeBar);

        mp = MediaPlayer.create(this, R.raw.shostakovich_moderato);
        mp.setVolume(0.5f, 0.5f);

        // Basic Audio Setup
        playTime = mp.getDuration();

        mp.setOnCompletionListener(mp -> playPause.setBackgroundResource(R.drawable.ic_play));

        // Audio Progress Bar
        playbackBar.setMax(playTime);
        playbackBar.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                if (fromUser) {
                    mp.seekTo(progress);
                }
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {

            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {

            }
        });

        // Handler for progressBar and timeLabels
        @SuppressLint("HandlerLeak") Handler handler = new Handler(){
            @Override
            public void handleMessage(@NonNull Message msg) {
                int time = msg.what;
                // Progress Bar
                playbackBar.setProgress(time);

                // Time Labels
                String elapsed = timeLabel(time);
                elapsedLabel.setText(elapsed);
                String remain = "-" + timeLabel(playTime - time);
                remainLabel.setText(remain);
            }
        };

        Thread thread = new Thread(){
            @Override
            public void run() {
                while (mp != null){
                    try {
                        Message msg = new Message();
                        msg.what = mp.getCurrentPosition();
                        handler.sendMessage(msg);
                        Thread.sleep(1000);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }
        };
        thread.start();

        // Volume Bar
        volumeBar.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                float change = progress / 100.0f;
                mp.setVolume(change, change);
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {

            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {

            }
        });
    }

    private String timeLabel(int time) {
        String string;
        int minutes = (time / 1000 / 60);
        int seconds = (time / 1000 % 60);

        string = Integer.toString(minutes) + ":";
        if (seconds < 10)
            string += "0";
        string += Integer.toString(seconds);

        return string;
    }

    public void playButton(View view) {
        if (mp.isPlaying()) {
            mp.pause();
            playPause.setBackgroundResource(R.drawable.ic_play);
        } else {
            mp.start();
            playPause.setBackgroundResource(R.drawable.ic_pause);
        }
    }

    @Override
    public void onBackPressed() {
        super.onBackPressed();
        mp.stop();
        finish();
    }
}