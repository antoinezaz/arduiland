package com.cassone.devmalin.ventilomolo;

import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;
import android.widget.EditText;

import com.cassone.devmalin.ventilomolo.models.Temperature;

import java.util.List;

import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;


public class RegisterActivity extends AppCompatActivity {

    @SuppressWarnings("unchecked")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        findViewById(R.id.edit_register).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                TemperatureService temperatureService = SetupTempService.setupTempService();
                Call<List<Temperature>> call = temperatureService.registerUser(
                        Integer.valueOf(((EditText) findViewById(R.id.edit_max_temp)).getText().toString()),
                        TemperatureService.API_KEY);
                call.enqueue(new Callback<List<Temperature>>() {
                    @Override
                    public void onResponse(Call<List<Temperature>> call, Response<List<Temperature>> response) {
                        if (!response.isSuccess()) {
                            Log.d("Register", "error");
                        } else {
                            Log.d("Register", "success");
                            startActivity(new Intent(RegisterActivity.this, MainActivity.class));
                        }
                    }

                    @Override
                    public void onFailure(Call<List<Temperature>> call, Throwable t) {
                        Log.d("Register", "Failure" + t.toString());
                    }
                });
            }
        });
    }
}
