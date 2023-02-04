/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import domainInfrastructure.Period;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author George
 */
public class PeriodTest {
    
    public PeriodTest() {
    }
    
    @Test
    public void testOverlaps1() throws ParseException {
        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
        Date s1 = sdf.parse("24/11/2015");
        Date e1   = sdf.parse("29/11/2015");
        Period p1 = new Period(s1, e1);
        Date s2 = sdf.parse("25/11/2015");
        Date e2 = sdf.parse("27/11/2015");
        Period p2 = new Period(s2,e2);
        assertEquals(true, p1.overlaps(p2));
        
    }
    
    @Test
    public void testOverlaps2() throws ParseException {
        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
        Date s1 = sdf.parse("24/11/2015");
        Date e1   = sdf.parse("29/11/2015");
        Period p1 = new Period(s1, e1);
        Date s2 = sdf.parse("30/11/2015");
        Date e2 = sdf.parse("1/12/2015");
        Period p2 = new Period(s2,e2);
        assertEquals(false, p1.overlaps(p2));
        
    }
}
