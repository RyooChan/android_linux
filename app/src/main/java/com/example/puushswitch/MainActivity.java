package com.example.puushswitch;

import androidx.appcompat.app.AppCompatActivity;

import android.app.Activity;
import android.os.Bundle;
import android.os.Handler;
import android.view.View;
import android.widget.EditText;
import android.widget.RadioGroup;
import android.widget.TextView;

import org.w3c.dom.Text;

import java.util.Timer;
import java.util.TimerTask;

public class MainActivity extends Activity {


    public int push;
    public int timecost;
    public int time = 3;
    public int count = 50;
    public int life = 3;
    public int data_in = 0;
    public boolean ans = false;
    public int stage = 3;
    public boolean go = true;
    public boolean flash = true;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        int input[] = new int[400];
        int data[] = new int[400];
        final int[] rand = new int[1];



        TimerTask task = new TimerTask(){
            int num = 0;
                Handler mHandler = new Handler();
                public void run(){
                    mHandler.postDelayed(new Runnable() {
                        @Override
                        public void run() {

                            SetMotorState(0, 0, 0);

                            if(go){
                                // stage별로 랜덤으로 화살표 값 생성 + data에 저장
                                time = 30;
                                count = 100;

                                for(int i = 0; i< stage; i++){
                                    try{
                                        rand[0] = (int)(Math.random()*8) + 1;
                                        data[i] = rand[0];
                                        ReceiveDotValue(data[i]);
                                        Thread.sleep(1500);
                                        ReceiveDotValue(0);
                                        Thread.sleep(500);

                                    }catch(Exception e) {
                                        System.out.println(e);
                                    }
                                }
                                go = false;
                                time = 3;
                                count = 100;
                            }

                                if(life>=0){

                                    ReceiveLedValue(life);

                                    // fnd 시간 출력
                                    timecost = ReceiveFndValue("000" + time);

                                    count--;

                                    if(count == 0){
                                        count = 10;
                                        time--;
                                    }

                                    if(time==0){
                                        time = 3;
                                        life--;
                                    }

                                }


                            int value;
                            value = DeviceOpen();

                            if (value != -1)
                                value = ReceivePushSwitchValue();

                            if (value != -1)
                                DeviceClose();

                            //값에 따라
                            String str = Integer.toString(value, 16);
                            switch (str) {
                                case "1":
                                    num = 1;
                                    flash = false;
                                    break;

                                case "2":
                                    num = 2;
                                    flash = false;
                                    break;

                                case "4":
                                    num = 3;
                                    flash = false;
                                    break;

                                case "8":
                                    num = 4;
                                    flash = false;
                                    break;

                                case "10":
                                    num = 5;
                                    flash = false;
                                    break;

                                case "20":
                                    num = 6;
                                    flash = false;
                                    break;

                                case "40":
                                    num = 7;
                                    flash = false;
                                    break;

                                case "80":
                                    num = 8;
                                    flash = false;
                                    break;

                                case "100":
                                    num = 9;
                                    flash = false;
                                    break;

                                case "0":
                                    if (!flash) {
                                        push = num;
                                        num = 0;
                                    }
                                    flash = true;
                                    break;
                            }


                            // push값 받아와서 화살표 비교하는 배열에 저장, 저장후 push값 초기화, push값 받아온 경우만 배열 비교가능
                            if(push!=0){
                                input[data_in] = push;
                                push = 0;
                                ans = true;
                            }

                            // 저장된 값이랑 입력한 값 비교, 맞으면 data_in 증가하고 더이상 비교 안함
                            if(input[data_in]==data[data_in] && ans){
                                data_in++;
                                ans = false;
                                time = 3;
                                count = 10;
                            }

                            else if(ans){
                                //목숨 하나 까기
                                life--;
                                go = true;
                                ans = false;
                                time = 3;
                                count = 100;
                                SetMotorState(0, 0, 0);
                                try{
                                    ReceiveDotValue(10);
                                    Thread.sleep(1500);
                                    ReceiveDotValue(0);
                                    Thread.sleep(500);
                                }catch(Exception e){
                                    e.printStackTrace();
                                }

                            }

                            if(data_in == stage){
                                try{
                                    ReceiveDotValue(11);
                                    Thread.sleep(1500);
                                    ReceiveDotValue(0);
                                    Thread.sleep(500);
                                }catch(Exception e){
                                    e.printStackTrace();
                                }

                                data_in = 0;
                                stage++;
                                go = true;
                                time = 30;
                                count = 100;
                            }

                            if(life == -1){
                                go = false;
                                ReceiveDotValue(11);
                                ReceiveFndValue("9999");
                                ReceiveLedValue(0);
                            }


                        }
                    }, 10);
                }
            };

            Timer t = new Timer();
            t.schedule(task, 100, 100);
        }



    public native String ReceiveDotValue(int x);
    public native String ReceiveLedValue(int x);
    public native int ReceiveFndValue(String ptr);
    public native String SetMotorState(int x, int y, int z);


    public native int DeviceOpen();
    public native int DeviceClose();
    public native int ReceivePushSwitchValue();

    static{
        System.loadLibrary("fpga-push-switch-jni");
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    // public native String stringFromJNI();
}
