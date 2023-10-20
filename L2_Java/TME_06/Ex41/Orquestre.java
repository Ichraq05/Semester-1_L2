package Ex41;

public class Orquestre {
    private Instrument[] instruments;
    private int nb_instruments;

    public Orquestre(int max_instruments){
        this.instruments = new Instrument[max_instruments];
        this.nb_instruments = 0;
    }

    public void ajouterInstrument(Instrument x){
        if(nb_instruments < instruments.length){
            instruments[nb_instruments] = x;
            nb_instruments ++;
        }
        else{
            System.out.println("L'orquestre est complet. Impossible d'ajouter plus d'instruments");
        }
    }

    public void jouer(){
        for (int i = 0; i < nb_instruments; i++){
            instruments[i].jouer();
        }
    }
}
