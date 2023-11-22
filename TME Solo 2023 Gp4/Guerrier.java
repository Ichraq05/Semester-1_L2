public class Guerrier extends Combattant{
    private String arme;
    private int degats;

    public Guerrier(String prenom,int force,String arme){
        super(prenom, force);
        this.arme = arme;
    }

    public void action(){
        if (arme == "marteau"){
            degats = force*2;
            System.out.println(super.toString() + ", classe : guerrier, arme : " + arme + ", attaque pour " + degats + " degats");
        }
        else{
            degats = force + ((int)((Math.random()*6)))+1;
            System.out.println(super.toString() + ", classe : guerrier, arme : " + arme + ", attaque pour " + degats + " degats");
        }
    }

    public String toString(){
        return super.toString() + ", classe : guerrier, arme : " + arme;
    }
}