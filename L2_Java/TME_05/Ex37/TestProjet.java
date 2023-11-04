public class TestProjet {
    public static void main(String[] args){
        System.out.println("Nombre de personnes : " + Personne.getNbPersonnes());

        Personne p1 = new Personne();
        Personne p2 = new Personne();

        System.out.println("Nouvel individu : " + p1.toString());
        System.out.println("Nouvel individu : " + p2.toString());

        System.out.println("Nombre de personnes : " + Personne.getNbPersonnes());
    }
}