abstract class TheatricalThings {
    abstract void print();
    abstract int getPrice();

    final void thingInf() {
        print();
        System.out.println("Цена: " + getPrice() + "\n");
    }
}
