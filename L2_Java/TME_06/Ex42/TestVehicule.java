public class TestVehicule {
    public static void main(String[] args) {
        Velo v1 = new Velo(17, "MyVTT");

        System.out.println(v1.toString());
        v1.transporter("Paris", "Lyon");
        v1.rouler(10);

        Voiture voit1 = new Voiture(5, 50, "BMW");
   
        System.out.println("\n" + voit1.toString());
        voit1.transporter(5,200);
        voit1.approvisionner(40);
        voit1.transporter(7,200);
        voit1.transporter(5,200);
    }
    
}