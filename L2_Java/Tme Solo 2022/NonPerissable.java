public class NonPerissable extends Marchandise{
    private String type;

    public NonPerissable(String type){
        super();
        this.type = type;
    }

    public String toString(){
        return super.toString() + " de type " + type;
    }
}