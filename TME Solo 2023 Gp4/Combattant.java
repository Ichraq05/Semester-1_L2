public class Combattant extends Heros {
    private int force;

    public Combattant(String prenom, int force){
        super(prenom);
        this.force = force;
    }

    public int getForce(){
        return force;
    }

    public String toString(){
        return prenom + " force :" + force;
    }
    
}