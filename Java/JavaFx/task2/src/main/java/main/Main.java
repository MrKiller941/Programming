package main;
import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.control.CheckBox;
import javafx.scene.control.Label;
import javafx.scene.layout.VBox;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
 
public class Main extends Application{
     
    public static void main(String[] args) {
        Application.launch(args);
    }
     
    @Override
    public void start(Stage stage) throws Exception {
        Parent root = FXMLLoader.load(getClass().getResource("/View.fxml"));
        Scene scene = new Scene(root);
         
        stage.setScene(scene);
         
        stage.setTitle("Ex2");
        stage.setWidth(400);
        stage.setHeight(400);
         
        stage.show();
    }
}