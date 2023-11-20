public class Marchandise{
    private int id;
    private double poids;

    public Marchandise(double poids){
    this.id = (int)Math.random()*1000;
    this.poids = poids;
    }

    public String toString(){
        return "La marchandise " + this.id + " de poids " + this.poids;
    }   
    
}