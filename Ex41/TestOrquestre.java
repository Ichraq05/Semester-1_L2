package Ex41;

public class TestOrquestre{
    public static void main(String[] args){
        Piano p1 = new Piano(88, 500, 3500);
        Guitare g1 = new Guitare("classique", 5, 300);

        System.out.println(p1.toString());
        p1.jouer();

        System.out.println(g1.toString());
        g1.jouer();

        
    }
}