public abstract class Heros {
    protected final int id;
    private String prenom;
    private static int cpt = 0;

    public Heros(String prenom){
        this.prenom = prenom;
        cpt++;
        this.id = cpt;
    }

    public abstract void action();

    public abstract String toString();
    
}