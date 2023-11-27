public class TestForet {
    public static void main(String[] args) {
        Foret foret = new Foret(5);

        for (int i = 0; i < 10; i++){
            double prob = Math.random()*100;
            if(prob < 30){
                Champignon pin = new Champignon("Pin");
                foret.placer(pin);
            }
            else{
                Champignon cepe = new Champignon("Cepe");
                foret.placer(cepe);
            }

        }

        System.out.println(foret.toString());;
    }
    
}