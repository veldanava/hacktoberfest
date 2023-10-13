using System;

public class BubbleSortExample
{
    public static void BubbleSort(int[] arr)
    {
        int n = arr.Length;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    // Swap arr[j] and arr[j + 1]
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    public static void Main(string[] args)
    {
        int[] arr = { 64, 34, 25, 12, 22, 11, 90 };

        Console.WriteLine("Array before sorting:");
        foreach (var item in arr)
            Console.Write(item + " ");

        // Sort the array
        BubbleSort(arr);

        Console.WriteLine("\nArray after sorting:");
        foreach (var item in arr)
            Console.Write(item + " ");
    }
}
