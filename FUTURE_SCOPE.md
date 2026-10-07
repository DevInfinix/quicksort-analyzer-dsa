# Future Scope

Current version supports adding student records, displaying them, and sorting them using quick sort on ID, Name or Marks (ascending/descending) with first, last or middle pivot. It shows the pivot and left/right partition sizes at every step along with comparison, swap, partition and recursive call counts.

The following features are planned for upcoming versions.

## Pending (part of project requirements)

- [ ] **Maximum recursion depth** - track how deep the recursion goes in each sort and display it with the other counts.
- [ ] **Unbalanced partition warning** - flag partitions where one side is much bigger than the other and show the total number of unbalanced partitions.
- [ ] **Test data generation** - generate random, already sorted and reverse sorted records automatically instead of typing them in.
- [ ] **Pivot comparison** - run all three pivot choices on the same data and show the results in one table to see how pivot choice affects performance.

## Possible improvements

- [ ] Allow names with spaces while entering records.
- [ ] Delete or edit an existing record.
- [ ] Search for a record by ID.
- [ ] Save records to a file and load them back.
- [ ] Median-of-three pivot as a fourth pivot option.
- [ ] Dynamic array so the record limit is not fixed at 100.
- [ ] Support employee and product records along with students.
