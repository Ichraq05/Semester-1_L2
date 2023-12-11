public class Etudiant {
    private int []notes = new int[5];
    private String nom;
    private int nbNotes = 0;

    public Etudiant(String nom){
        this.nom = nom;
    }

    public void enterNote(int note) throws TabNotesPleinException{
        if (nbNotes >= notes.length){
            throw new TabNotesPleinException("Impossible d'ajouter la note : " + note + " à l'étudiant " + nom + "\nLe nombre de notes max est atteintes.");
        }
        else{
            notes[nbNotes] = notes;
            nbNotes++;
        }
    }

    public String toString(){
        res = "Etudiant : " + nom + "\nNotes : ";
        for (int x : notes){
            res += x + " ";
        }
        return res;
    }
    
}