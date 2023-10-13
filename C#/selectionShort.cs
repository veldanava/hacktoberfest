using System;

public class SelectionSortExample
{
    public static void SelectionSort(int[] arr)
    {
        int n = arr.Length;

        for (int i = 0; i < n - 1; i++)
        {
            int minIndex = i;
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] < arr[minIndex])
                    minIndex = j;
            }

            // Swap the found minimum element with the first element
            int temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
        }
    }

    public static void Main(string[] args)
    {
        int[] arr = { 64, 25, 12, 22, 11 };

        Console.WriteLine("Array before sorting:");
        foreach (var item in arr)
            Console.Write(item + " ");

        SelectionSort(arr);

        Console.WriteLine("\nArray after Selection Sort:");
        foreach (var item in arr)
            Console.Write(item + " ");
    }
}
