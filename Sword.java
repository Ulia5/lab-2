public class Sword extends Props {

    Sword(int hazardLevel, int serviceLife, int price){
        this.hazardLevel = hazardLevel;
        this.serviceLife = serviceLife;
        this.price = price;
        this.periodOfUse = 0;
        this.status = true;
    }

    public void changePeriodOfUse(int period) {
        periodOfUse += period;
        securityCheck();
    }
}
