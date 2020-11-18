package com.qrofeus.sdlpracticals;

import android.app.AlertDialog;
import android.app.Dialog;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatDialogFragment;

public class Dialog_Student_Details extends AppCompatDialogFragment {
    private String text;

    public Dialog_Student_Details(String text) {
        this.text = text;
    }

    @NonNull
    @Override
    public Dialog onCreateDialog(@Nullable Bundle savedInstanceState) {
        AlertDialog.Builder builder = new AlertDialog.Builder(getActivity());
        View view = getActivity().getLayoutInflater().inflate(R.layout.dialog_student_details,null);

        final TextView dialogText = view.findViewById(R.id.dialog_text);
        dialogText.setText(text);

        builder.setView(view);

        return builder.create();
    }
}
