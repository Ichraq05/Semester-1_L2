public class Ex15_Q3 {
    public static void main(String[] args) {
        Complexe complexe1 = new Complexe(1, 2);
        Complexe complexe2 = new Complexe(-2, 0);
        Complexe complexe3 = new Complexe(3, -4);

        System.out.println("Comlexe 1 : " + complexe1);
        System.out.println("Comlexe 2 : " + complexe2);
        System.out.println("Comlexe 3 : " + complexe3);

        // Tester s'ils sont réels ou pas
        System.out.println("\nComlexe 1 est réel : " + complexe1.estReel());
        System.out.println("Comlexe 2 est réel : " + complexe2.estReel());
        System.out.println("Comlexe 3 est réel : " + complexe3.estReel());

        Complexe somme = complexe1.addition(complexe2);
        Complexe produit = complexe2.multiplication(complexe3);

        System.out.println("\nSomme de Comlexe 1 et Comlexe 2 : " + somme);
        System.out.println("Produit de Comlexe 2 et Comlexe 3 : " + produit);
    }
}

