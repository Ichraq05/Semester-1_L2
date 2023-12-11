public class TestEtudiants {
    public static void main(String[] args) {
        for (String arg : args){
            try{
                // Tentative de conversion en entier
                int note = Integer.parseInt(arg);
                System.out.print(note + " est une note, ");
            }
            catch (NumberFormatException e){
                // Si la conversion en entier échoue, c'est probablement un nom
                System.out.print("\n" + arg + " est un nom, ");
            }
        }
        System.out.println();
    }
}