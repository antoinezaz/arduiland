package com.cassone.devmalin.ventilomolo;

import android.graphics.Color;
import android.os.Handler;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;

import android.util.Log;

import com.cassone.devmalin.ventilomolo.models.Temperature;
import com.github.mikephil.charting.charts.LineChart;

import java.util.ArrayList;
import java.util.List;

import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;

public class MainActivity extends AppCompatActivity {

    private LineChart lineChartTemp;

    public static final String TEMPERATURE = "Temperature";
    private static final String TAG = "MainActivity";
    private final static int INTERVAL = 1000;
    Handler mHandler =new Handler();

    private List<Temperature> tabTemp;

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
            TemperatureService temperatureService = SetupTempService.setupTempService();
            Call<List<Temperature>> call = temperatureService.getAllTemperature(TemperatureService.API_KEY);
            call.enqueue(new Callback<List<Temperature>>() {
                @Override
                public void onResponse(Call<List<Temperature>> call, Response<List<Temperature>> response) {
                    if (!response.isSuccess()) {
                        Log.d(TAG, "error");
                    } else {
                        Log.d(TAG, "success");
                        tabTemp = response.body();
                    }
                }

                @Override
                public void onFailure(Call<List<Temperature>> call, Throwable t) {
                    Log.d(TAG, "Failure" + t.toString());
                }
            });


            updateLineChart();
            mHandler.postDelayed(mhandlerTask, INTERVAL);
        }
    };


    public void updateLineChart() {

    }
}
