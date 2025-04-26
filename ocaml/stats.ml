(* stats.ml *)

(* Calculate mean of a list of integers *)
let mean lst =
  (* Sum all elements in the list and divide by the number of elements *)
  let sum = List.fold_left (+) 0 lst in
  float_of_int sum /. float_of_int (List.length lst)

(* Calculate median of a list of integers *)
let median lst =
  (* Sort the list to find the median value *)
  let sorted = List.sort compare lst in
  let n = List.length sorted in
  if n mod 2 = 0 then
    (* If even number of elements, average the two middle elements *)
    let a = List.nth sorted (n/2 - 1) in
    let b = List.nth sorted (n/2) in
    (float_of_int (a + b)) /. 2.0
  else
    (* If odd number of elements, return the middle element *)
    float_of_int (List.nth sorted (n/2))

(* Calculate mode of a list of integers *)
let mode lst =
  (* Create a frequency table to count occurrences of each element *)
  let freq_tbl =
    List.fold_left (fun acc x ->
      let count = try List.assoc x acc with Not_found -> 0 in
      (x, count + 1) :: List.remove_assoc x acc
    ) [] lst
  in
  (* Find the maximum frequency count *)
  let max_count =
    List.fold_left (fun m (_, c) -> if c > m then c else m) 0 freq_tbl
  in
  (* Filter elements that have the maximum frequency and return them *)
  freq_tbl
  |> List.filter (fun (_, c) -> c = max_count)
  |> List.map fst, max_count

(* Main function to read input, calculate statistics, and print results *)
let () =
  (* Convert command line arguments to a list of integers *)
  let args = Array.to_list Sys.argv |> List.tl in
  let nums = List.map int_of_string args in
  if nums = [] then (
    (* Print usage message if no numbers are provided *)
    Printf.printf "Usage: ocaml stats.ml <n1> <n2> ...\n";
    exit 1
  );
  (* Calculate mean, median, and mode *)
  let m = mean nums in
  let med = median nums in
  let modes, freq = mode nums in
  (* Print the calculated statistics *)
  Printf.printf "Mean: %.2f\n" m;
  Printf.printf "Median: %.2f\n" med;
  Printf.printf "Mode (%d occurrences): %s\n"
    freq
    (String.concat ", " (List.map string_of_int modes))
