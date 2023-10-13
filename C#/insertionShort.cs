using System;

public class InsertionSortExample
{
    public static void InsertionSort(int[] arr)
    {
        int n = arr.Length;
        for (int i = 1; i < n; i++)
        {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }

    public static void Main(string[] args)
    {
        int[] arr = { 12, 11, 13, 5, 6 };

        Console.WriteLine("Array before sorting:");
        foreach (var item in arr)
            Console.Write(item + " ");

        InsertionSort(arr);

        Console.WriteLine("\nArray after Insertion Sort:");
        foreach (var item in arr)
            Console.Write(item + " ");
    }
}
