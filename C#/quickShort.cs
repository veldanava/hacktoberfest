using System;

public class QuickSortExample
{
    public static void QuickSort(int[] arr, int low, int high)
    {
        if (low < high)
        {
            int partitionIndex = Partition(arr, low, high);

            // Sort elements before and after the partition index
            QuickSort(arr, low, partitionIndex - 1);
            QuickSort(arr, partitionIndex + 1, high);
        }
    }

    private static int Partition(int[] arr, int low, int high)
    {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                // Swap arr[i] and arr[j]
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        // Swap arr[i+1] and arr[high] (or the pivot)
        int temp1 = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp1;

        return i + 1;
    }

    public static void Main(string[] args)
    {
        int[] arr = { 10, 80, 30, 90, 40, 50, 70 };

        Console.WriteLine("Array before sorting:");
        foreach (var item in arr)
            Console.Write(item + " ");

        // Sort the array
        QuickSort(arr, 0, arr.Length - 1);

        Console.WriteLine("\nArray after sorting:");
        foreach (var item in arr)
            Console.Write(item + " ");
    }
}
