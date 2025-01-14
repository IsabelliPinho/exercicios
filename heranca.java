//1
public class Poligono{
    double base;
    double altura;
    public Poligono(double base, double altura){
        this.base = base;
        this.altura = altura;
    }
   
}
public class Triangulo extends Poligono{
    public Triangulo(double base, double altura){
        super(base,altura);
    }
     public double calcularArea(){
        return((base*altura)/2);}
}
public class Quadrado extends Poligono{
    public Quadrado(double base, double altura){
        super(base,altura);
    }
     public double calcularArea(){
        
        return(base*base);
    }
}
public class Retangulo extends Poligono{
    public Retangulo(double base, double altura){
        super(base,altura);
    }
     public double calcularArea(){
        return(base*altura);
    }
}
public class Main{
    public static void main(String[]args){
    Triangulo triangulo = new Triangulo(2,3);
    Quadrado quadrado = new Quadrado(2,2);
    Retangulo retangulo = new Retangulo(3,3);
    
    System.out.println(triangulo.calcularArea());
     System.out.println(quadrado.calcularArea());
     System.out.println(retangulo.calcularArea());
    
}}
