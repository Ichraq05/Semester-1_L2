public class Carre extends Rectangle{

    public Carre(double cotes){
        super(cotes,cotes);
    }

    public double surface(){
        return longueur*longueur;
    }

    public double perimetre(){
        return 4*longueur;
    }
    
}