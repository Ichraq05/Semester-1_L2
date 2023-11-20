public class Navire {
    private Marchandise []tab = new Marchandise[10];
    private static int id = 0;
    private double charge;
    private double capacite;
    private String pays;    
    private static int nb_mar = 0;

    public Navire(String pays, double capacite){
        this.pays = pays;
        this.capacite = capacite;
        id++;
        nb_mar++;
    }

    public Navire (double capacite){
        this(None, capacite);
    }

    public int CalculerPoidsCharge(){
        int res = 0;
        for(Marchandis x : tab){
            res += x.poids;
        }
    }

    
}