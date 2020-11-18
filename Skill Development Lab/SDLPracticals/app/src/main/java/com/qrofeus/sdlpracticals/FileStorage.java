package com.qrofeus.sdlpracticals;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;

public class FileStorage extends AppCompatActivity {

    private static final String FILE_NAME = "StudentData.txt";

    private EditText name;
    private EditText college;
    private EditText phone;
    private EditText mail;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_file_storage);

        name = findViewById(R.id.edit_name);
        college = findViewById(R.id.edit_college);
        phone = findViewById(R.id.edit_phone);
        mail = findViewById(R.id.edit_mail);
    }

    public void saveData(View view){
        String output = createText();
        if (output.equals("null")){
            Toast.makeText(this, "Please enter name and contact details", Toast.LENGTH_SHORT).show();
            return;
        }
        FileOutputStream outputStream = null;

        try {
            outputStream = openFileOutput(FILE_NAME, MODE_APPEND);
            outputStream.write(output.getBytes());
            Toast.makeText(this, "Updated file: " + getFilesDir() + "/" + FILE_NAME, Toast.LENGTH_LONG).show();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if (outputStream != null)
                try {
                    outputStream.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
        }
    }

    private String createText() {
        String text_name = name.getText().toString();
        String text_college = college.getText().toString();
        String text_phone = phone.getText().toString();
        String text_mail = mail.getText().toString();

        if (text_name.isEmpty())
            return "null";
        if (text_phone.isEmpty() && text_mail.isEmpty())
            return "null";

        name.getText().clear();
        college.getText().clear();
        phone.getText().clear();
        mail.getText().clear();

        return "Name: " + text_name +
                "\nCollege: " + text_college +
                "\nContact Details\nPhone: " + text_phone +
                "\nMail ID: " + text_mail + "\n\n";
    }

    public void showData(View view){
        FileInputStream inputStream = null;

        try {
            inputStream = openFileInput(FILE_NAME);
            InputStreamReader reader = new InputStreamReader(inputStream);
            BufferedReader reader1 = new BufferedReader(reader);
            StringBuilder builder = new StringBuilder();
            String text;

            while ((text = reader1.readLine()) != null){
                builder.append(text).append("\n");
            }

            Dialog_Student_Details details = new Dialog_Student_Details(builder.toString());
            details.show(getSupportFragmentManager(), "File Data");
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if (inputStream != null)
                try {
                    inputStream.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
        }
    }
}