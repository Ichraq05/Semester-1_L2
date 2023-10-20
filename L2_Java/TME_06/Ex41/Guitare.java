package Ex41;

public class Guitare extends Instrument{
    private String type;

    public Guitare(String type, int prix, int poids){
        super(prix, poids);
        this.type = type;
    }

    public String toString(){
        return "Guitare : "+ type +", "+ super.toString();
    }

    public void jouer(){
        System.out.println("La guitare joue.");
    }
}