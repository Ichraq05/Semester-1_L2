public class TestProjet {
    public static void main(String[] args){
        System.out.println("Nombre de personnes : " + Personne.getNbPersonnes());

        Personne p1 = new Personne();
        Personne p2 = new Personne();
        System.out.println("Nouvel individu : " + p1.toString());
        System.out.println("Nouvel individu : " + p2.toString());

        System.out.println("Nombre de personnes : " + Personne.getNbPersonnes());

        System.out.println("\nNombre de Trio : " + Trio.getCpt());

        Trio t1 = new Trio();
        Trio t2 = new Trio();
        System.out.println(t1.toString());
        System.out.println(t2.toString());

        System.out.println("Nombre de Trio : " + Trio.getCpt());
    }
}