package Unitone;

public class Interface implements Inter {
    @Override
    public void horn(){
        System.out.println("Beep Beep");
    }

    static void main(String[] args) {
        Interface inter = new Interface();
        inter.horn();
    }

}

