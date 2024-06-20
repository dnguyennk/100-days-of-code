import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;
import javafx.event.*;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class ElectronicStoreApp extends Application {
    private ElectronicStore model;
    private ElectronicStoreView view;

    public ElectronicStoreApp(){
        model = ElectronicStore.createStore();
        view = new ElectronicStoreView(model);
    }
    public void start(Stage primaryStage){
        Pane aPane = new Pane();
        aPane.getChildren().add(view);

        //Enable buttons
        SetButtonsHandler();

        primaryStage.setTitle("Electronic Store Application - " + model.getName());
        primaryStage.setScene(new Scene(aPane));
        primaryStage.show();

        view.update(true, true, true, false);
    }

    public void handleAddButtonPress(){
        boolean disableAddButton = view.getStockList().getSelectionModel().getSelectedIndex() < 0;
        int selection = view.getStockList().getSelectionModel().getSelectedIndex();
        ArrayList<Product> availableProducts = model.getAvaibleProduct();
        HashMap<Product, Integer> cart = model.getCart();
        if (selection >=0){
            Product p = availableProducts.get(selection);
            if (cart.containsKey(p)){
                cart.put(p, cart.get(p) + 1);
            }
            else{
                cart.put(p, 1);
            }
            if(cart.get(p) == p.getStockQuantity()){
                availableProducts.remove(p);
                disableAddButton = true;
            }
        }
        view.update(disableAddButton, true, false, false);
    }
    public void handleRemoveButtonPress(){
        int selection = view.getCartList().getSelectionModel().getSelectedIndex();
        Product p = model.getCurrentCartList().get(selection);
        boolean disableAddButton = view.getStockList().getSelectionModel().getSelectedIndex() < 0;
        boolean disableCompleteButton = view.getCartList().getItems().isEmpty();
        HashMap<Product, Integer> cart = model.getCart();
        ArrayList<Product> availableProducts = model.getAvaibleProduct();
        if (selection >=0){
            if (cart.containsKey(p)){
                cart.put(p, cart.get(p) - 1);

                if(p.getStockQuantity() > cart.get(p)){
                    availableProducts.add(p);
                }
                if (cart.get(p) == 0){
                    cart.remove(p);
                    disableCompleteButton = true;
                }
            }
        }

        view.update(disableAddButton, true, disableCompleteButton, false);
    }
    public void handleCompleteButtonPress() {
        HashMap<Product, Integer> cart = model.getCart();
        boolean disableAddButton = view.getStockList().getSelectionModel().getSelectedIndex() < 0;
        double revenue = 0;
        for (Map.Entry<Product, Integer> set: cart.entrySet()){
            revenue+= set.getKey().sellUnits(set.getValue());
        }
        model.setRevenue(revenue);
        model.setSalesCount(model.getSalesCount()+1);
        model.getCart().clear();
        view.getRemoveButton().setDisable(true);
        view.update(disableAddButton, true, true, false);

    }
    public void handleResetButtonPress(){
        this.model = ElectronicStore.createStore();
        view.setModel(this.model);
        view.update(true, true, true, false);
    }

    public void SetButtonsHandler(){
        view.getStockList().setOnMousePressed(new EventHandler<MouseEvent>() {
            public void handle(MouseEvent mouseEvent){
                boolean disableAddButton = view.getStockList().getSelectionModel().getSelectedIndex() < 0;
                boolean disableCompleteButton = view.getCartList().getItems().isEmpty();
                view.update(disableAddButton, true, disableCompleteButton, false);
            }
        });
        view.getCartList().setOnMousePressed(new EventHandler<MouseEvent>() {
            public void handle(MouseEvent mouseEvent){
                boolean disableAddButton = view.getStockList().getSelectionModel().getSelectedIndex() < 0;
                boolean disableCompleteButton = view.getCartList().getItems().isEmpty();
                boolean disableRemoveButton = view.getCartList().getSelectionModel().getSelectedIndex() < 0;
                view.update(disableAddButton, disableRemoveButton, disableCompleteButton, false);
            }
        });

        //Plug in buttons
        view.getAddButton().setOnAction(new EventHandler<ActionEvent>() {
            public void handle(ActionEvent actionEvent) {
                handleAddButtonPress();
            }
        });

        view.getRemoveButton().setOnAction(new EventHandler<ActionEvent>() {

            public void handle(ActionEvent actionEvent) {
                handleRemoveButtonPress();
            }
        });

        view.getCompleteButton().setOnAction(new EventHandler<ActionEvent>() {

            public void handle(ActionEvent actionEvent) {
                handleCompleteButtonPress();
            }
        });

        view.getResetButton().setOnAction(new EventHandler<ActionEvent>() {

            public void handle(ActionEvent actionEvent) {
                handleResetButtonPress();
            }
        });
    }

    public static void main(String[] args){ launch(args);}


}
