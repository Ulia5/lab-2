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
        System.out.println("������� ���������: " + hazardLevel);
        System.out.println("���� ������: " + serviceLife);
        System.out.println("������ �������������: " + periodOfUse);
        if(status) {
            System.out.println("������: ������������");
        }
        else {
            System.out.println("������: �������");
        }
    }

    @Override
    public int getPrice() {
        return price;
    }
}
