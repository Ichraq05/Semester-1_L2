public class ChampignonToxique {
    private String nom;
    private double poids;

    public ChampignonToxique(String nom){
        this.nom = nom;
        this.poids = Math.random()*3;
    }

    public double getPoids(){
        return poids;
    }

    public String toString(){
        return nom + " " + poids + " kg";
    }
}