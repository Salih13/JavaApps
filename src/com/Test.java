package com;

import java.util.Scanner;

public class Test {

	private static Scanner input;

	public static void main(String[] args) {

		input = new Scanner(System.in);
		Test test = new Test();
		int elemanSayisi;
		int birinciSayi;
		int ikinciSayi;
		int yeniSayi;
		int toplamMasraf = 0;
		
		do {
			System.out.print("Dizi uzunlugu: ");
			elemanSayisi = input.nextInt();
		}while(elemanSayisi < 2 || elemanSayisi > 10000);
		

		int[] num = new int[elemanSayisi];

		for (int i = 0; i < elemanSayisi; i++) {
			do {
				System.out.print(i + 1 + ". Sayi: ");
				num[i] = input.nextInt();
			}while(num[i] < 0 || num[i] > 100000);
		}
		
		int j = num.length - 2;
		for (int i = 0; i < elemanSayisi - 1; i++) {
			birinciSayi = test.kucukElemaniGetir(num);
			test.dizidenSil(birinciSayi, num);
			num[num.length-1] = -1;
			
			ikinciSayi = test.kucukElemaniGetir(num);
			test.dizidenSil(ikinciSayi, num);
			yeniSayi = birinciSayi + ikinciSayi;
			num[j] = yeniSayi;
			toplamMasraf = toplamMasraf + yeniSayi;
			j--;
		}

		System.out.println("Toplam Masraf: " + toplamMasraf);

	}

	public int kucukElemaniGetir(int[] num) {
		int min = num[0];
		for (int i = 0; i < num.length; i++)
			if (min > num[i] && num[i] != -1)
				min = num[i];
		return min;
	}

	public void dizidenSil(int sayi, int[] num) {
		int indis = indisBul(sayi, num);
		for (int i = 0; i < num.length - 1; i++) {
			if (i >= indis)
				num[i] = num[i + 1];
		}
	}

	public int indisBul(int sayi, int[] num) {
		int indis = 0;
		for (int i = 0; i < num.length; i++)
			if (sayi == num[i]) 
				indis = i;			
		return indis;
	}

}
