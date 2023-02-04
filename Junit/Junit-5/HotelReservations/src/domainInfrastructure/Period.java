package domainInfrastructure;

import java.util.Date;

public class Period {

    private Date startDate;
    private Date endDate;

    public Period(Date startDate, Date endDate) {
        this.startDate = startDate;
        this.endDate = endDate;
    }

    public Date getStartDate() {
        return startDate;
    }

    public Date getEndDate() {
        return endDate;
    }

    public boolean overlaps(Period p) {
        Date pStartD = p.getStartDate();
        Date pEndD = p.getEndDate();
        /**
         * Δύο περίοδοι Α και Β επικαλύπτονται χρονικά αν
         * startA<=endB AND endA>=startB
         */
        if (startDate.compareTo(pEndD) <= 0 && endDate.compareTo(pStartD) >= 0) {
            return true;
        }
        return false;
    }
}
