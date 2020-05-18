
import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        Pilha pilha = new Pilha();
        PilhaBoolean pilhaBoolean = new PilhaBoolean();
        int quantidade = in.nextInt();
        String comando;
        String expressao;
        int tamanho;
        
        for(int i = 0; i<quantidade; i++) {
        	comando = in.next();
        	expressao = in.next();
        	tamanho = expressao.length();
        	if(comando.equals("VAL")) {
        		char membro;
        		for(int j = 0; j<tamanho; j++) {
        			membro = expressao.charAt(j);
        			if(membro=='1'){
        				pilhaBoolean.empilha(true);
        			}else if(membro=='0'){
        				pilhaBoolean.empilha(false);
        			}else {
        				switch(membro) {
        				case '~':
        					boolean x1 = pilhaBoolean.desempilha();
        					pilhaBoolean.empilha(!x1);
        					break;
        				case '^':
        					boolean y1 = pilhaBoolean.desempilha();
        					boolean y2 = pilhaBoolean.desempilha();
        					pilhaBoolean.empilha(y1&&y2);
        					break;
        				case 'v':
        					boolean z1 = pilhaBoolean.desempilha();
        					boolean z2 = pilhaBoolean.desempilha();
        					pilhaBoolean.empilha(z1||z2);
        					break;
        				case '>':
        					boolean w1 = pilhaBoolean.desempilha();
        					boolean w2 = pilhaBoolean.desempilha();
        					pilhaBoolean.empilha((!w2)||w1);
        					break;
        				}
        			}
        		}
        		if(pilhaBoolean.desempilha()) {
        			System.out.println("1");
        		}else {
        			System.out.println("0");
        		}
        	}else {
        		char membro;
        		for(int j = 0; j<tamanho; j++) {//for que representa o tamanho da expressao
        			membro = expressao.charAt(j);
        			if(membro=='1'){
        				pilha.empilha("1");
        			}else if(membro=='0'){
        				pilha.empilha("0");
        			}else {
        				switch(membro) {
        				case '~':
        					String x1 = pilha.desempilha();
        					//String empilha1 = "";
        					//empilha1 = empilha1.format("(~%s)", x1);
        					pilha.empilha("(~"+x1+")");
        					break;
        				case '^':
        					String y1 = pilha.desempilha();
        					String y2 = pilha.desempilha();
        					//String empilha2 = "";
        					//empilha2 = empilha2.format("(%s^%s)", y2, y1);
        					pilha.empilha("("+y2+"^"+y1+")");
        					break;
        				case 'v':
        					String z1 = pilha.desempilha();
        					String z2 = pilha.desempilha();
        					//String empilha3 = "";
        					//empilha3 = empilha3.format("(%sv%s)", z2, z1);
        					pilha.empilha("("+z2+"v"+z1+")");
        					break;
        				case '>':
        					String w1 = pilha.desempilha();
        					String w2 = pilha.desempilha();
        					//String empilha4 = "";
        					//empilha4 = empilha4.format("(%s>%s)", w2, w1);
        					pilha.empilha("("+w2+">"+w1+")");
        					break;
        				}
        			}
        		}
        		System.out.println(pilha.desempilha());
        	}
        }
    }//fim do main
}

class Pilha{
    private Pilha apontador;
    private String element;

    public Pilha(){
    	this.apontador = null;
        this.element = null;
    }

    public Pilha(String x){
    	this.apontador = null;
        this.element = x;
    }

    public void empilha(String x){
    	Pilha inicio = new Pilha(x);
    	inicio.apontador = this.apontador;
    	this.apontador = inicio;
    }

    public String desempilha(){
    	String aux = this.apontador.element;
        this.apontador = this.apontador.apontador;
    	return aux;
    }

}

class PilhaBoolean{
	private PilhaBoolean apontador;
    private boolean element;
    
    public PilhaBoolean(){
        this.apontador = null;
        this.element = false;
    }
    
    public PilhaBoolean(boolean x){
        this.apontador = null;
        this.element = x;
    }
    
    public void empilha(boolean x){
    	PilhaBoolean inicio = new PilhaBoolean(x);
    	inicio.apontador = this.apontador;
    	this.apontador = inicio;
    }
    
    public boolean desempilha(){
    	boolean aux = this.apontador.element;
        this.apontador = this.apontador.apontador;
    	return aux;
    }
    
}