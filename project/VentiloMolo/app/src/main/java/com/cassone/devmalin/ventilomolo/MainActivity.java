package com.cassone.devmalin.ventilomolo;

import android.graphics.Color;
import android.os.Handler;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.util.Log;
import com.github.mikephil.charting.charts.LineChart;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {

    private LineChart lineChartTemp;

    public static final String TEMPERATURE = "Temperature";
    private static final String TAG = "MainActivity";
    private final static int INTERVAL = 5000;
    Handler mHandler =new Handler();

    private ArrayList<Temperature> tabTemp;

    private double minTemp = 0;
    private double maxTemp = 0;
    private float time = 0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        lineChartTemp = (LineChart) findViewById(R.id.chart1);
        lineChartTemp.setDescription("Graphique de température");
        lineChartTemp.setNoDataTextDescription("Données attendues");
        lineChartTemp.setBackgroundColor(Color.LTGRAY);

        tabTemp = new ArrayList<>();

        mhandlerTask.run();
    }

    Runnable mhandlerTask = new Runnable()
    {

        @Override
        public void run() {
            startListenerTemp();
            updateLineChart();
            mHandler.postDelayed(mhandlerTask, INTERVAL);
        }
    };

    private void startListenerTemp(){
        BroadcastReceiver myBroadcastReceiver = new BroadcastReceiver() {

            @Override
            public void onReceive(final Context context, final Intent intent) {
                // Faire quelquechose au résultat
                Temperature temp = intent.getParcelableExtra(TEMPERATURE);
                if (temp != null){
                    Log.v(TAG, "onPostExecute: " + temp.getId() +  " " + temp.getCelcius() + " "
                            + temp.getFahrenheit());

                    if (minTemp > temp.getCelcius() || minTemp == 0)
                        minTemp = temp.getCelcius();
                    else if (maxTemp < temp.getCelcius())
                        maxTemp = temp.getCelcius();

                    tabTemp.add(temp);
                }
            }
        };


        // enregistrement du BroadcastReceiver
        IntentFilter filter = new IntentFilter("com.example.myapp.EVENT_DONE");
        registerReceiver(myBroadcastReceiver, filter);

        // lancement du service
        Intent intent = new Intent(this, TempService.class);
        startService(intent);
    }

    public void updateLineChart() {

    }
}
