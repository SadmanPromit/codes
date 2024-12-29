# infer_chunk: v1 © 2024 Sadman Sakib Khan Promit
# "nvidia/Llama-3.1-Nemotron-70B-Instruct-HF" 131 GB
# "nvidia/Mistral-NeMo-Minitron-8B-Base" 15.6 GB
# "google/gemma-7b"
# "microsoft/phi-2" 5.18 GB
import time
from airllm import AutoModel

model_path = "nvidia/Llama-3.1-Nemotron-70B-Instruct-HF"

def main():
    model = AutoModel.from_pretrained(model_path)
    while True:
        input_text = input("prompt: ")
        MAX_LENGTH = int(input("token: "))
        inputs = model.tokenizer(input_text, return_tensors = "pt").to("cuda")
        start_time = time.time()
        output = model.generate(
            input_ids = inputs["input_ids"],
            attention_mask = inputs["attention_mask"],
            max_new_tokens = MAX_LENGTH,
            do_sample = True,
            top_k = 50,
            top_p = 0.95,
            pad_token_id = model.tokenizer.pad_token_id,
            eos_token_id = model.tokenizer.eos_token_id,
        )
        generated_ids = output[:, inputs["input_ids"].shape[-1]:]
        output_text = model.tokenizer.decode(generated_ids[0], skip_special_tokens = True).strip()
        end_time = time.time()
        execution_time = end_time - start_time
        print(f"[{output_text}]")
        try:
            with open("70Binfer_log.txt", "a") as file:
                file.write(f"[{input_text}] [{output_text}] [{MAX_LENGTH} * {execution_time / MAX_LENGTH / 60:.2f} = {execution_time / 60:.2f}m]\n")
        except Exception as e:
            print(f"[{MAX_LENGTH} * {execution_time / MAX_LENGTH / 60:.2f} = {execution_time / 60:.2f}m]")

if __name__ == "__main__":
    main()