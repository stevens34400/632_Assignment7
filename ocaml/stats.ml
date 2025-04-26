(* stats.ml *)

(* Calculate mean *)
let mean lst =
  let sum = List.fold_left (+) 0 lst in
  float_of_int sum /. float_of_int (List.length lst)

(* Calculate median *)
let median lst =
  let sorted = List.sort compare lst in
  let n = List.length sorted in
  if n mod 2 = 0 then
    let a = List.nth sorted (n/2 - 1) in
    let b = List.nth sorted (n/2) in
    (float_of_int (a + b)) /. 2.0
  else
    float_of_int (List.nth sorted (n/2))

(* Calculate mode *)
let mode lst =
  let freq_tbl =
    List.fold_left (fun acc x ->
      let count = try List.assoc x acc with Not_found -> 0 in
      (x, count + 1) :: List.remove_assoc x acc
    ) [] lst
  in
  let max_count =
    List.fold_left (fun m (_, c) -> if c > m then c else m) 0 freq_tbl
  in
  freq_tbl
  |> List.filter (fun (_, c) -> c = max_count)
  |> List.map fst, max_count

let () =
  let args = Array.to_list Sys.argv |> List.tl in
  let nums = List.map int_of_string args in
  if nums = [] then (
    Printf.printf "Usage: ocaml stats.ml <n1> <n2> ...\n";
    exit 1
  );
  let m = mean nums in
  let med = median nums in
  let modes, freq = mode nums in
  Printf.printf "Mean: %.2f\n" m;
  Printf.printf "Median: %.2f\n" med;
  Printf.printf "Mode (%d occurrences): %s\n"
    freq
    (String.concat ", " (List.map string_of_int modes))
