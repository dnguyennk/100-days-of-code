import javafx.scene.control.*;
import javafx.scene.layout.Pane;
import java.util.HashMap;
import java.util.List;


import javafx.collections.FXCollections;

public class ElectronicStoreView  extends Pane {
    private ElectronicStore model;
    private Button resetButton, addButton, removeButton, completeButton;
    private Label storeSummary, storeStock, cart, numSales, revenueLabel, averageSales, mostPopular;
    private ListView<String> stockList, currentCartList, popularItemsList;
    private TextField  sales, rev, avgSale;


    public ElectronicStoreView(ElectronicStore model) {
        this.model = model;
        AddAllComponents();

    }
    public void update(boolean disableAddButton, boolean disableRemoveButton, boolean disableCompleteButton, boolean disableResetButton){
        HashMap<Product, Integer> currentCart = model.getCart();
        List<String> available = model.getAvaibleProduct().stream().filter(p -> !currentCart.containsKey(p) || currentCart.get(p) < p.getStockQuantity()).map(Product::toString).toList();
        stockList.setItems(FXCollections.observableArrayList(available));
        currentCartList.setItems(FXCollections.observableArrayList(model.getCurentCartNames()));
        popularItemsList.setItems(FXCollections.observableArrayList(model.getPopularList()));
        String value = String.format("$%.2f", model.getMoney());
        String revenue = String.format("$%.2f", model.getRevenue());
        String averageSale = String.format("$%.2f", model.getRevenue()/model.getSalesCount());
        if (model.getSalesCount() == 0){
            averageSale = "N/A";
        }

        sales.setText("" + model.getSalesCount());
        rev.setText(revenue);
        avgSale.setText(averageSale);
        cart.setText("Current Cart: (" + value+")");
        addButton.setDisable(disableAddButton);
        removeButton.setDisable(disableRemoveButton);
        resetButton.setDisable(disableResetButton);
        completeButton.setDisable(disableCompleteButton);
    }


    public void AddAllComponents(){
        //Create label
        storeSummary = new Label("Store Summary:");
        storeSummary.relocate(40, 10);

        storeStock = new Label("Store Stock:");
        storeStock.relocate(280, 10);

        cart= new Label("Current Cart: ($.0.00)");
        cart.relocate(550, 10);

        numSales = new Label("# Sales:");
        numSales.relocate(25, 35);

        revenueLabel = new Label("Revenue:");
        revenueLabel.relocate(18, 65);

        averageSales = new Label("$ / Sale:");
        averageSales.relocate(25, 95);

        mostPopular = new Label("Most Popular Items:");
        mostPopular.relocate(30,130);

        //Create ListView
        popularItemsList = new ListView<>();

        popularItemsList.relocate(10, 155);
        popularItemsList.setPrefSize(165, 180);

        stockList = new ListView<>();
        stockList.relocate(185, 30);
        stockList.setPrefSize(280, 305);

        currentCartList = new ListView<>();
        currentCartList.relocate(475, 30);
        currentCartList.setPrefSize(305, 305);

        //Create TextField
        sales = new TextField();
        sales.relocate(72, 30);
        sales.setPrefSize(100, 15);
        sales.setText("0");

        rev = new TextField();
        rev.relocate(72, 60);
        rev.setPrefSize(100, 15);
        rev.setText("0.00");

        avgSale = new TextField();
        avgSale.relocate(72, 90);
        avgSale.setPrefSize(100, 15);
        avgSale.setText("N/A");


        //Create the buttons
        addButton = new Button("Add to Cart");
        addButton.relocate(250, 340);
        addButton.setPrefSize(155, 45);
        addButton.setDisable(true);


        removeButton = new Button("Remove from Cart");
        removeButton.relocate(475, 340);
        removeButton.setPrefSize(150, 45);
        removeButton.setDisable(true);

        completeButton = new Button("Complete Sale");
        completeButton.relocate(626, 340);
        completeButton.setPrefSize(155, 45);
        completeButton.setDisable(true);

        resetButton = new Button("Reset Store");
        resetButton.relocate(20, 340);
        resetButton.setPrefSize(140, 45);

        //Create Buttons

        getChildren().addAll(storeSummary, storeStock,  cart,
                numSales, revenueLabel, averageSales, mostPopular,
                popularItemsList, currentCartList, stockList,
                sales, rev, avgSale,
                addButton, removeButton, completeButton, resetButton);

        setPrefSize(800,400);
    }


    public ListView<String> getStockList(){ return stockList;}
    public ListView<String> getCartList(){ return currentCartList;}
    public Button getAddButton(){ return addButton; }
    public Button getRemoveButton(){ return removeButton; }

    public Button getCompleteButton() { return completeButton; }
    public Button getResetButton() { return resetButton; }

    public void setModel(ElectronicStore model){
        this.model = model;
    }
}