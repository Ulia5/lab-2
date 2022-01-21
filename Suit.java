public class Suit extends Costume{
    private String type;

    Suit(String color, int size, int price, String type) {
        super(color, size, price);
        this.type = type;
    }

    @Override
    public void print() {
        super.print();
        System.out.println("“ип: " + type);
    }

    @Override
    public int getPrice() {
        return (int) (price * 1.01);
    }
}
