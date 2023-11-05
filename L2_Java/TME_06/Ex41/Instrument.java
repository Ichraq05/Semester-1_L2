public abstract class Instrument {
    private int prix;
    private double poids;

    public Instrument(int prix, double poids){
        this.prix = prix;
        this.poids = poids;
    }

    public String toString(){
        return "poids : "+ poids + " kg, prix : "+ prix + " eruos";
    }

    public abstract void jouer();
    
}