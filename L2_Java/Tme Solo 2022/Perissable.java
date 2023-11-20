public class Perissable extends Date {
    private String date;

    public Perissable(){
        super();
        this.date = super.toString();
    }

    public String toString(){
        return "La marchandise " + this.id + " de poids " + this.poids + "est perissable le " + date;
    }
    
}