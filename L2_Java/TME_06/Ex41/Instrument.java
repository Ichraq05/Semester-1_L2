package Ex41;

public class Instrument{
    private int prix;
    private int poids;

    public Instrument(int prix, int poids){
        this.prix = prix;
        this.poids = poids;
    }

    public String toString(){
        return "poids : "+ poids +" kg, prix : "+ prix +" euros.";
    }

    public void jouer(){
        
    }
}

