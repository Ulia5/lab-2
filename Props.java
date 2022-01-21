public abstract class Props extends TheatricalThings {
    protected int hazardLevel;
    protected int serviceLife;
    protected int periodOfUse;
    protected int price;
    protected boolean status;

    protected void securityCheck () {
        if(periodOfUse >= serviceLife && hazardLevel > 2) {
            status = false;
        }
    }

    @Override
    protected void print() {
        System.out.println("Уровень опасности: " + hazardLevel);
        System.out.println("Срок службы: " + serviceLife);
        System.out.println("Период использования: " + periodOfUse);
        if(status) {
            System.out.println("Статус: используется");
        }
        else {
            System.out.println("Статус: списано");
        }
    }

    @Override
    public int getPrice() {
        return price;
    }
}
