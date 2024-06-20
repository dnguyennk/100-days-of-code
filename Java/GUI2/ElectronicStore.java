//Class representing an electronic store
//Has an array of products that represent the items the store can sell
import javax.swing.plaf.ProgressBarUI;
import java.util.*;


public class ElectronicStore {
    public final int MAX_PRODUCTS = 10; //Maximum number of products the store can have
    private String name;
    private ArrayList<Product> stock; //Array to hold all products

    private double revenue;
    private int salesCount;
    private double money;
    HashMap<Product, Integer> currentCart;

    public ElectronicStore(String initName) {
        revenue = 0.0;
        name = initName;
        stock = new ArrayList<>();
        currentCart = new HashMap<>();
        salesCount = 0;
    }

    public static ElectronicStore createStore() {
        ElectronicStore store1 = new ElectronicStore("Watts Up Electronics");
        Desktop d1 = new Desktop(100, 10, 3.0, 16, false, 250, "Compact");
        Desktop d2 = new Desktop(200, 10, 4.0, 32, true, 500, "Server");
        Laptop l1 = new Laptop(150, 10, 2.5, 16, true, 250, 15);
        Laptop l2 = new Laptop(250, 10, 3.5, 24, true, 500, 16);
        Fridge f1 = new Fridge(500, 10, 250, "White", "Sub Zero", false);
        Fridge f2 = new Fridge(750, 10, 125, "Stainless Steel", "Sub Zero", true);
        ToasterOven t1 = new ToasterOven(25, 10, 50, "Black", "Danby", false);
        ToasterOven t2 = new ToasterOven(75, 10, 50, "Silver", "Toasty", true);
        store1.addProduct(d1);
        store1.addProduct(d2);
        store1.addProduct(l1);
        store1.addProduct(l2);
        store1.addProduct(f1);
        store1.addProduct(f2);
        store1.addProduct(t1);
        store1.addProduct(t2);
        return store1;
    }
    public String getName() {
        return name;
    }

    //Adds a product and returns true if there is space in the array
    //Returns false otherwise
    public boolean addProduct(Product newProduct) {
        if (stock.size() < MAX_PRODUCTS) {
            stock.add(newProduct);
            return true;
        }
        return false;
    }
    public ArrayList<Product> getAvaibleProduct(){
        ArrayList<Product> product = new ArrayList<>();
        for (int i = 0; i < stock.size(); i++ ){
            if (stock.get(i).getStockQuantity() > 0){
                product.add(stock.get(i));
            }
        }
        return product;
    }


    public ArrayList<String> getPopularList(){
        ArrayList<String> popularList = new ArrayList<>();
        ArrayList<Product> copyList = new ArrayList<>();
        for (Product p: stock){
            if (p != null){
                copyList.add(p);
            }
        }
        copyList.sort(Comparator.comparing(Product::getSoldQuantity).reversed());
        for (int i = 0; i< 3; i++){
            popularList.add(copyList.get(i).toString());
        }
        return popularList;

    }

    public HashMap<Product, Integer> getCart(){ return currentCart;};

    public ArrayList<Product> getCurrentCartList(){
        ArrayList<Product> list = new ArrayList<>();
        for (Map.Entry<Product, Integer> set: currentCart.entrySet()){
            Product product = set.getKey();
            list.add(product);
        }
        return list;
    }
    public ArrayList<String> getCurentCartNames(){
        ArrayList<String> list = new ArrayList<>();
        for (Map.Entry<Product, Integer> set: currentCart.entrySet()){
            Product product = set.getKey();
            Integer count = set.getValue();
            list.add(count.toString() + " x " + product.toString());
        }
        return list;
    }
    public double getMoney(){
        double price= 0;
        for (Map.Entry<Product, Integer> set: currentCart.entrySet()){
            Product product = set.getKey();
            Integer count = set.getValue();
            price+= product.getPrice() * count;
        }
        return price;

    }
    public int getSalesCount(){
        return salesCount; }
    public void setSalesCount(int i){
        salesCount = i;
    }
    public double getRevenue(){ return revenue;}
    public void setRevenue(double d){ revenue += d;}


}