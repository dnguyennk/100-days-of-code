import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;
import javafx.event.*;
import javafx.scene.input.MouseEvent;
import java.util.Scanner;

public class DVDCollectionApp1  extends Application {
    private DVDCollection model;
    private Scanner userInput1;
    private Scanner userInput2;
    private Scanner userInput3;

    public DVDCollectionApp1(){
        model = DVDCollection.example1();
        userInput1 = new Scanner(System.in);
        userInput2 = new Scanner(System.in);
        userInput3 = new Scanner(System.in);

    }

    public void start(Stage primaryStage) {
        Pane  aPane = new Pane();

        // Create the view
        DVDCollectionAppView1  view = new DVDCollectionAppView1();
        view.update(model, 0);

        aPane.getChildren().add(view);
        primaryStage.setTitle("My DVD Collection");
        primaryStage.setResizable(false);
        primaryStage.setScene(new Scene(aPane));
        primaryStage.show();

        // Event handler to handle the Add button
        view.getButtonPane().getAddButton().setOnAction(new EventHandler<ActionEvent>() {
            public void handle(ActionEvent addEvent) {
                System.out.println("Please enter the song title: ");
                String title = userInput1.nextLine();

                System.out.println("Please enter the song's year: ");
                int year = userInput2.nextInt();

                System.out.println("Please enter the song's length: ");
                int length = userInput3.nextInt();
                model.add(new DVD(title, year, length));
                view.update(model, 0);
            }
        });
        // An event handler to handle the Delete button
        view.getButtonPane().getDeleteButton().setOnAction(new EventHandler<ActionEvent>() {
            public void handle(ActionEvent deleteEvent) {
               String s = view.getTitleList().getSelectionModel().getSelectedItem();
               model.remove(s);
               view.update(model, 0);
            } });
        // Make sure that whenever the user clicks any of the three ListView
        // they all stay synchronized
        // Event handler that handle the event the user click any of the song's title
        view.getTitleList().setOnMousePressed(new EventHandler<MouseEvent>()
        {
            public void handle(MouseEvent mouseEvent) {
                int selectedIndex = view.getTitleList().getSelectionModel().getSelectedIndex();
                view.getYearList().getSelectionModel().select(selectedIndex);
                view.getLengthList().getSelectionModel().select(selectedIndex);
                view.update(model, selectedIndex);
            }
        });
        // Event handler that handle the event  the user click any of the song's year
        view.getYearList().setOnMousePressed(new EventHandler<MouseEvent>()
        {
            public void handle(MouseEvent mouseEvent) {
                int selectedIndex = view.getYearList().getSelectionModel().getSelectedIndex();
                view.getTitleList().getSelectionModel().select(selectedIndex);
                view.getLengthList().getSelectionModel().select(selectedIndex);
                view.update(model, selectedIndex);
            }
        });
        // Event handler that handle the event the user click any of the song's length
        view.getLengthList().setOnMousePressed(new EventHandler<MouseEvent>()
        {
            public void handle(MouseEvent mouseEvent) {
                int selectedIndex = view.getLengthList().getSelectionModel().getSelectedIndex();
                view.getYearList().getSelectionModel().select(selectedIndex);
                view.getTitleList().getSelectionModel().select(selectedIndex);
                view.update(model, selectedIndex);
            }
        });

    }



    public static void main(String[] args) {
        launch(args);
    }
}