package com.example;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;

public class Controller {
    
     @FXML
    private TextField text1;

    @FXML
    private TextField text2;

    @FXML
    private Button button;

    @FXML
    void onClick() {
        String temp = text1.getText();
        text1.setText(text2.getText());
        text2.setText(temp);
        if(button.getText() != "<-") {
            button.setText("<-");
        }
        else {
            button.setText("->");
        }
    }
}

